
#include <string>
#include "hashTable.h"
#include "hashValues.h"
#include "hashTableItem.h"

HashTable::HashTable()
{
    for(int i = 0; i<BUCKETS; i++)
    {
        m_hashTable[i] = nullptr;
    }
}

void HashTable::insert(int idx, pHashTableItem item) {
    if(m_hashTable[idx] != nullptr) {
        if(m_hashTable[idx]->isDuplicate(item)) {
            return; //TODO: should this return a value
        }
        m_hashTable[idx]->handleInsertCollision(item);
    } else {
        m_hashTable[idx] = item;
    }
}

void HashTable::remove(std::string key, int idx)
{
    if(m_hashTable[idx] == nullptr) {
        return; //TODO: this is an error
    }

    pHashTableItem tableEntry = m_hashTable[idx];
    if(key == tableEntry->getKey()) {
        tableEntry->clear();
        m_hashTable[idx] = nullptr;
        return;
    }

    tableEntry->removeListItem(key);
    tableEntry->promoteListItem();
}

pHashTableItem HashTable::find(std::string key, int idx) {
    if(m_hashTable[idx] == nullptr) {
        return(nullptr);
    }

    pHashTableItem tableEntry = m_hashTable[idx];
    if(key == tableEntry->getKey()) {
        return(tableEntry);
    }

    return(tableEntry->findListItem(key));
}

void HashTable::dump() {
    for(int i = 0; i < BUCKETS; i++) {
        if(m_hashTable[i] != nullptr) {
            pHashTableItem item = m_hashTable[i];
            item->dump(item, i);    
        }
    }
}
