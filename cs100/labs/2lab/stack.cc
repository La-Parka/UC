#include <iostream>
using namespace std;

class Stack
{
    private:
        int* newStack;
        int capacity;
        int size;
    public:
        Stack()
        {
            newStack = new int[0];
            this->capacity = 0;
            this->size = 0;
        }
        void expand()
       {
           if ( capacity == 0)
                capacity = 1;
        capacity *= 2;
        int* temp = new int[capacity];   //temporary variable assigned to new size
    
        for(int i = 0; i < capacity; i++)
            temp[i] = newStack[i];
    
        newStack = temp;
    
        temp = NULL;

}

        void push (int x)
        {
            if(size + 1 > capacity)
                expand();
            size++;
           
            newStack[size-1] = x;
        }   
        
        void pop ()
        {
            if(size == 0)
            {
                cout << "Error" << endl;
                exit(1);
            }
             size = size-1;
             //newStack = new int[size];
         }
         ~Stack()
         {
             //for(int i = size-1; i >= 0; i++)
               //  delete &newStack[i];
               delete [] newStack;
         }
         void print ()
         {
             cout << "Size:" << size << endl;
             cout << "Capacity: " << capacity << endl;
             for ( int i = 0; i < size; i++)
                cout << newStack[i] << " ";
                
            cout << endl <<endl;
         }
         
};

int main()
{
    Stack y;
    y.push(1);
    y.print();
    y.push(2);
    y.print();
    y.push(4);
    y.print();
    y.pop();
    y.print();
    y.pop();
    y.print();
    y.pop();
    y.print();
    y.pop();
    y.print();
    
    return 0;
}
    
