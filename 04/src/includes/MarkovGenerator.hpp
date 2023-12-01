#pragma once

#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::string str;

class MarkovGenerator
{
    std::unordered_map<str, std::vector<str>> m_tokens;

    void clean_word(str&) const;

    str shitpost(const str&) const;

    void read_tokens(std::ifstream&);

public:
    explicit MarkovGenerator(const str&);

    str generate_sentence(bool);
};