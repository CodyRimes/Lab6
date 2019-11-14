
class DynamicArray {
   public:
      DynamicArray();
      ~DynamicArray();
      void append(int newVal);
      int at(int index);
      int sum();
      bool remove(int valToDelete);

      void print();
      int cap() { return capacity; }

   private:
      int* arr;
      int len; // Number of elements actually populated
      int capacity; // New variable - this is the current capacity of the array

};
