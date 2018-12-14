#pragma once

#include <string>

#include <unordered_set>

struct Translatable
{
    typedef std::unordered_set<Translatable*> TrSet;
    typedef std::unordered_set<const char *> StrSet;

    static TrSet *m_trSet;
    static StrSet *m_strSet;

    Translatable(const std::string & = std::string(), const char *d = nullptr);
    ~Translatable();

    std::string text;
    const char *domain = nullptr;
    const char *i18n = nullptr;

    const char *translate();
    void set(std::string t, const char *d = nullptr);

    static void update();
    static const char *store(const std::string&);
    
    static void init();
    static void cleanup();
};
