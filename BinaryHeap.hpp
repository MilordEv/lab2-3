#ifndef __BINARYHEAP__
#define __BINARYHEAP__

template <typename T>
class BinaryHeap {
   private:
      T* items;
      int maxSize;
      int heapSize;

   public:
      BinaryHeap(T* items, int length);  
      BinaryHeap(); 
      BinaryHeap(const BinaryHeap<T> &binaryHeap); 

      ~BinaryHeap();

      bool Find(T value);
      void AddElement(T value);  
      void OutHeap();  
      void OutMatrix(); 
      T Getmax();
      void Heapify(int);

      //BinaryHeap<T>* GetSubHeap(T value);  
};


template <typename T>
BinaryHeap<T>::BinaryHeap(T* items, int length) {
   this->maxSize = length + 2;
   this->heapSize = length;
   this->items = new T[this->maxSize];

   for (int i = 0; i < length; i++) {
      this->items[i] = items[i];
   }

   Heapify(0);
}

template <typename T>
BinaryHeap<T>::BinaryHeap() {
   this->maxSize = 0;
   this->heapSize = 0;
   this->items = nullptr;
}

template <typename T>
BinaryHeap<T>::BinaryHeap(const BinaryHeap<T> &binaryHeap) {
   this->maxSize = binaryHeap.maxSize;
   this->heapSize = binaryHeap.heapSize;
   this->items = new T[this->maxSize];

   for (int i = 0; i < binaryHeap.heapSize; i++) {
      this->items[i] = binaryHeap.items[i];
   }

   this->Heapify(0);
}

template <typename T>
BinaryHeap<T>::~BinaryHeap() {
   delete[] this->items;
}



template <typename T>
bool BinaryHeap<T>::Find(T value) {
   for (int i = 0; i < this->heapSize; i++) {
      if (this->items[i] == value) {
         return true;
      }
   }
   return false;
}

template <typename T>
void BinaryHeap<T>::AddElement(T item) {
   if (!this->heapSize) {
      this->maxSize = 7;
      this->items = new T[this->maxSize];
   }

   if (this->maxSize == this->heapSize) {
      T* newItems = new T[this->maxSize * 2];
      for (int i = 0; i < this->maxSize; i++) {
         newItems[i] = this->items[i];
      }

      delete this->items;
      this->items = newItems;
      this->maxSize *= 2;
   }

   int i = this->heapSize;
   int parent = (i - 1) / 2;
   this->items[i] = item;

   while(parent >= 0 && i > 0)  {
      if(this->items[i] > this->items[parent]) {
         int buf = this->items[i];
         this->items[i] = this->items[parent];
         this->items[parent] = buf;
      }

      i = parent;
      parent = (i - 1) / 2;
   }
   this->heapSize++;
}

template <typename T>
void BinaryHeap<T>::OutHeap() {
   int i = 0;
   int k = 1;
   while(i < this->heapSize) {
      while((i < k) && (i < this->heapSize)) {
         std::cout << this->items[i] << " ";
         i++;
      }
      std::cout << std::endl;
      k = k * 2 + 1;
   }
}

template <typename T>
void BinaryHeap<T>::OutMatrix() {
   for(int i = 0; i < this->heapSize; i++) {
      std::cout << this->items[i] << " ";
   }
   std::cout << std::endl;
}

template <typename T>
void BinaryHeap<T>::Heapify(int i) {
   int left = 2 * i + 1;
   int right = 2 * i + 2;
   int buf;

   if(left < heapSize) {
      if(this->items[i] < this->items[left]) {
         buf = this->items[i];
         this->items[i] = this->items[left];
         this->items[left] = buf;
         this->Heapify(left);
      }
   }

   if(right < heapSize) {
      if(this->items[i] < this->items[right]) {
         buf = this->items[i];
         this->items[i] = this->items[right];
         this->items[right] = buf;
         this->Heapify(right);
      }
   }
}

template <typename T>
T BinaryHeap<T>::Getmax() {
   T value;
   value = this->items[0];
   this->items[0] = this->items[this->heapSize - 1];
   this->heapSize--;
   this->Heapify(0);
   return value;
}

/*template <typename T>
BinaryHeap<T>* BinaryHeap<T>::GetSubHeap(T value) {
   if (!(this->Find(value))) {
      return nullptr;
   }

   int i = 0;
   int k = 1;
   while(i < this->heapSize) {
      while((i < k) && (i < this->heapSize)) {
         std::cout << this->items[i] << " ";
         i++;
      }
      std::cout << std::endl;
      k = k * 2 + 1;
   }   
}*/


#endif   