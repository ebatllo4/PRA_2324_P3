#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "dict.h"
#include "tableentry.h"
#include <iostream>

#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V>{

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;

	int h(std::string key){
		int suma = 0;
		for( size_t i=0; i<key.length(); i++){
			suma += static_cast<int>(key.at(i)); //convierte en ASCII
		}
		return suma % max;
	}


    public:
        
	HashTable(int size){
		table = new ListLinked<TableEntry<V>>[size];
		n = 0;
		max = size;
	}


	~HashTable(){
		delete[] table;
	}


	int capacity(){
		return max;
	}


	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		out << "===================" << std::endl;
		for (int i = 0; i < th.max; i++){
			out<< "Cubeta " << i << std::endl;
			out << th.table[i] << std::endl; 
		}
		out << "==================" << std::endl;
		return out;
	}

	
	V operator[](std::string key){
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);
		if(posicion >= 0){
			return table[cubeta].get(posicion).value;
		}else{
			throw std::runtime_error("No se ha podido encontrar la clave");
		}
	}

	void insert(std::string key, V value) override{
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);
		if(posicion != -1){
			throw std::runtime_error("La clave ya existe");
		}else{
			table[cubeta].insert(table[cubeta].size(), TableEntry(key, value));
			n++;
		}
	}

	
	V search(std::string key) override{
		int cubeta = h(key);
                int pos = table[cubeta].search(key);                        
                if (pos >= 0){
                return table[cubeta].get(pos).value;    
                }else{
			throw std::runtime_error("No se ha podido encontrar la clave");
                }
	}

	
	V remove(std::string key) override{
		int cubeta = h(key);
                int pos = table[cubeta].search(key);
                if (pos >= 0){
			V valor = table[cubeta].get(pos).value;
                        table[cubeta].remove(pos);
			n--;
			return valor;
                }else{
                        throw std::runtime_error("No se ha podido encontrar la clave");
                }

	}

	
	int entries() override{
		return n;
	}
       
};

#endif
