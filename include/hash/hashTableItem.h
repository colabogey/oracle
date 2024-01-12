#pragma once
#include <string>
#include <memory>
#include <list>

class HashTableItem
{
public:
    HashTableItem() = default;
    ~HashTableItem();
    HashTableItem(std::string key, std::string value) 
    {
        m_key = key;
        m_value = value;
    }
     
    std::string getKey() { return m_key; };
    std::string getValue() { return m_value; };
    //size_t getListSize() { return m_list.size(); };
    bool isDuplicate(std::shared_ptr<HashTableItem> item);
    void handleInsertCollision(std::shared_ptr<HashTableItem>);
    void removeListItem(std::string);
    void promoteListItem();
    std::shared_ptr<HashTableItem> findListItem(std::string);
    void clear();

private:
    std::string m_key;
    std::string m_value;
    std::list<std::shared_ptr<HashTableItem>> m_list;
};

typedef std::shared_ptr<HashTableItem> pHashTableItem;
