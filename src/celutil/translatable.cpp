
#include <cstring>
#include <libintl.h>

#include "translatable.h" 

Translatable::Translatable()
{
    m_trSet.insert(this);
}

Translatable::~Translatable()
{
    m_trSet.erase(this);
}

const char *Translatable::translate()
{
    i18n = dgettext(domain, /*context,*/ text.data());
    return i18n;
}

void Translatable::set(std::string t, const char *d, const char *c)
{
    text = t;
    domain = d;
    context = c;
    i18n = nullptr;
}

void Translatable::update()
{
    for (auto it : m_trSet)
        it->translate();
}

const char *Translatable::store(const std::string &s)
{
    char *n = new char[s.size()];
    std::strcpy(n, s.data());
    m_strSet.insert(n);
    return n;
}

Translatable::TrSet Translatable::m_trSet;
Translatable::StrSet Translatable::m_strSet;
