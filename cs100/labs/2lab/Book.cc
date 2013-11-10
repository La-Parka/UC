#include <iostream>
using namespace std;

class Book
{
    private:
        struct Infos 
        {
            string title;
            string author;
            string year;
            Infos* next; 
            Infos (string titl, string auth, string yr)
            :title (titl), author (auth), year (yr)
            {
                next = NULL;
            }
        };
        Infos* head;
        Infos* tail;
        int size;
    public:
        Book():head(NULL),size(0){} 
        void add()
        {
            string titl,
                    auth,
                    yr; 
            cout << "Enter title: ";
            getline (cin, titl);
            cout << "Enter author: ";
            getline (cin, auth);
            cout << "Enter year: " ;
            getline (cin, yr);
            //cin.ignore();

    Infos* newInfos = new Infos (titl,auth, yr);
    newInfos->title = titl;
    newInfos->next = NULL;
    
    if (size == 0)
    {
        head = newInfos;
        tail = newInfos;
    }
    else
    {
        if (head->title >= titl)
        {
            newInfos->next = head;
            head = newInfos;
        }
        else
        {
            Infos* temp = head;
            for (Infos* it = head->next; temp != NULL; temp = temp->next)
            {
                if (it)
                {
                    if (it->title >= titl)
                    {
                        temp->next = newInfos;
                        newInfos->next = it;
                        break;
                    }
                }
                else if (temp == tail)
                {
                    tail->next = newInfos;
                    newInfos->next = NULL;
                    tail = newInfos;
                }
                
                if (it)
                {
                    it = it->next;
                }
            }
        }
    }
    
    size++;


        }
            
        Infos* search(string title)
        {
            Infos* temp = head;
            while ( temp -> next != NULL)
            {
                if (temp -> title == title)
                    return temp;
                else 
                    temp = temp-> next;
            }
            
            return NULL;
        }
        void remove(string title)
        {
            Infos* temp = head;
            if (head == NULL)
            {
                cerr << "Error" << endl;
                exit(1);
            }
            
            if( head -> title == title )
            {
                head = temp -> next;
                delete temp;
                size--;
                return;
            }
            
            for(Infos* it = head -> next; it != NULL; temp = temp -> next)
            {
                if ( it -> title == title)
                {
                    temp -> next = it -> next;
                    
                    if ( it == tail )
                        tail = temp;
                        
                    delete it;
                    size --;
                    break;
                }
                else 
                {
                    it = it -> next;
                }
            }
        }
        void print()
        {
            for(Infos* it = head; it != NULL; it = it-> next)
            {
                cout << "Title: " << it->title << endl;
                cout << "Author: " << it->author << endl;
                cout << "Year: " << it->year << endl << endl;
            }
            
        }
        Infos* n2Last(int x)
        {
            if ( x == 1 || x == 0 )
            {
                return tail;
            }
            else
            {
                unsigned element = size - x;
                
                unsigned i = 0;
                for (Infos* it = head; it != NULL; it = it -> next)
                {
                    if ( i == element)
                        return it;
                    i++;
                }
            }
            return NULL;
        }
                
                
}; 
int main()
{
    Book x;
    x.add();
    cout << endl;
    x.add();
    cout << endl;
    x.add();
    cout << endl;
    x.add();
    cout << endl;
    x.remove("a");
    x.print();
    x.search ("a");
    
    cout << x.n2Last(2)->title <<endl;
    
    return 0;
}
