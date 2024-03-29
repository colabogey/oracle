
#include "quiz.h"

Quiz::Quiz(std::string sAry[], int size) {
    for (int i = 0; i < size; i++) {
        m_items.insert(sAry[i]);
    }

    for (int i = 0; i < size; i++) {
        m_allStrings.push_front(sAry[i]);
    }
}

bool Quiz::findItem(std::string s) {
    _findItem(s, 0, s.length() - 1);
    if (m_items.size() == m_found.size()) {
        return true;
    } else {
        return false;
    }
}

bool Quiz::findAllItems(std::string s) {
    bool bRet = true;
    for (std::string strList : m_allStrings) {
        std::size_t found = s.find(strList);
        if (found == std::string::npos) {
            bRet = false;
        }
    }
    return bRet;
    ;
}

void Quiz::_findItem(std::string s, int begin, int end) {
    if (begin > end) {
        return;
    }

    std::string sSub = s.substr(0, begin + 1);
    auto search = m_items.find(sSub);
    if (search != m_items.end()) {
        m_found.insert(*search);
        std::string newS = s.substr(sSub.length(), end);
        _findItem(newS, 0, newS.length() - 1);
    } else {
        _findItem(s, begin + 1, end);
    }
}
