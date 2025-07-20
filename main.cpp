#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
    int* arr = nullptr;
    int size = 0;
    int capicty;

public:
    // Constructor
    Vector(int size) {
        if (size <= 0)
            size = 1;
        this->size = size;
        capicty=size+10;
        arr = new int[capicty];
    }

    // Destructor
    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }

    // Set value at index
    void set(int idx, int value) {
        assert(0 <= idx && idx < size);
        arr[idx] = value;
    }

    // Get value at index
    int get(int idx) {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }

    // Push back a value (resize the array)
    void push_back(int val) {
        if(size == capicty)
            expandcapicty();
        arr[size++] = val;

    }
    void push_front(int val){
    int front =arr[0];
    arr[0]=val;
    }
    //swap between two index in array
    void swapbetween_frontandback(){
        assert( size>=2);
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
    }
    //delete last index in array
    void deletes(){
    int *arr2=new int[size-1];
    for(int i=0;i<size ;i++){
        arr2[i]=arr[i];
        size--;
        break;
    }

    }
    //make capicty large if you wanna make is grater
 void expandcapicty(){
     capicty*=2;
    int* arr2 = new int[capicty];
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }

       swap(arr , arr2);
        delete[] arr2;


    }
    //insert value in index
    void insert(int val,int idx){
        if(size==capicty)
            expandcapicty();

        for (int i=size-1;i>=idx;i--){

        arr[i+1]=arr[i];
        }

        arr[idx]=val;
        size++;


    }
    //shift elment 0 to right
    void right_Rotate(){
     // if(size==capicty)
           // expandcapicty();

      for(int i=size-1;i>=0;--i){
        arr[i+1]=arr[i];

      }
      arr[0]=arr[size];
      size-1;

    }
    //get indx of elment and remove it
    int pop(int idx){
       for(int i=idx;i<size-1;i++){

            arr[i]=arr[i+1];

       }

      size--;
       return idx;
    }
    //12345 23451
    void left_Rotate(){
     // if(size==capicty)
           // expandcapicty();

      for(int i=0;i<=size;i++){
        arr[i]=arr[i+1];

      }
      arr[size]=arr[0];
      size-1;

    }
  int find_transposation(int val){
  for(int i=0;i<size-1;i++){
    if(arr[i]==val){
        int temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }

  }
  return arr[val];

  }
    //right by times ss
     void Right_Rotate_time(int time){
     while(time--){
        right_Rotate();
     }

     }

    // Find index of a value
    int find(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }

    // Print all values
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Vector v(10);

    // Set values
    for (int i = 0; i < 10; i++) {
        v.set(i, i );  // set values like 0, 2, 4, ...
    }

    //v.print();

    //Push back some values
    //v.push_back(100);
    //v.push_back(200);
    //v.swapbetween_frontandback();
    //v.deletes();
     // v.insert(18,2);
   // v.right_Rotate();
     // v.print();
      //v.left_Rotate();
     // cout<< "the idex is::"<<v.pop(2)<<endl;
      cout<<"the val is::"<<v.find_transposation(5)<<endl;
      v.print();


    // Find example
    cout << "Index of 100: " << v.find(100) << endl;
    cout << "Index of 7: " << v.find(7) << endl;

    return 0;
}
