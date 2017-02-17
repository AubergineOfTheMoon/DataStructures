#pragma once
#ifndef ANIMALCOLLECTION_H
#define ANIMALCOLLECTION_H

const int maxAnimals = 2;

template <class T> class AnimalCollection {
private:
	T *animalsInCollection;
	int currentAnimalNum;
public:
	AnimalCollection();
	void addAnimal(T*);
	T removeAnimal();
	int getAnimalNum();
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
	animalsInCollection = new T[maxAnimals];
	currentAnimalNum = 0;
};


template<class T>
inline void AnimalCollection<T>::addAnimal(T* h) {
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
	return currentAnimalNum;
};

