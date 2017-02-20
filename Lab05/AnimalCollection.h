#pragma once
#ifndef ANIMALCOLLECTION_H
#define ANIMALCOLLECTION_H

const int maxAnimals = 2;

template <class T> class AnimalCollection {
private:
	T *animalsInCollection; // array of animals in animal collection
	int currentAnimalNum;   // Variable that stores number of animals in the collection
	                        // and the next open space in the animal collection. 

public:
	AnimalCollection(); 
	void addAnimal(T*);
	T removeAnimal();
	int getAnimalNum();
	
	// Exception classes
	class FullCollection;
	class EmptyCollection;

	//FullCollection Class Definition
	class FullAnimalCollection {
	private:
		int index;
	public:
		FullAnimalCollection(int i) { index = i; }
		int getValue() { return index; }
	};
	//EmptyCollection Class Definition
	class EmptyAnimalCollection {
	public:
		EmptyAnimalCollection() { }
	};
};

#endif


template <class T>
inline AnimalCollection<T>::AnimalCollection() {
	// Default constructor for animal collection
	animalsInCollection = new T[maxAnimals];
	currentAnimalNum = 0;
};


template<class T>
inline void AnimalCollection<T>::addAnimal(T* h) {
	// Add animal to animal collection
	if (currentAnimalNum < maxAnimals) {
		animalsInCollection[currentAnimalNum] = *h;
		currentAnimalNum++;
	}
	else {
		throw FullAnimalCollection(currentAnimalNum + 1);
	}

};

template<class T>
inline T AnimalCollection<T>::removeAnimal() {
	// Remove animal from animal collection
	if (currentAnimalNum > 0) {
		currentAnimalNum--;
		return animalsInCollection[currentAnimalNum];
	}
	else {
		throw EmptyAnimalCollection();
	}

};

template<class T>
inline int AnimalCollection<T>::getAnimalNum() {
	// Return number of animals in the collection.
	return currentAnimalNum;
};