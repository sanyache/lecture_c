#include<iostream>
#include<vector>
#include <limits>

using namespace std;
struct Book{
    int book_id;
    string title;
    string author;
    string subject;
};
int main(){
    vector<Book>Books;
    int n;
    cin>>n;
    Books.resize(n);
    for(int i=0; i<n; i++){

        Book book;
        cin>>book.book_id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, book.title);
        getline(cin, book.author);
        getline(cin, book.subject);
        Books.push_back(book);
    }
    int n_id;
    cin>>n_id;
    int Id[n_id];
    for(int i=0; i<n_id; i++){
        cin>>Id[i];
    }
    for(int i=0; i<n_id; i++){
        bool is_find = false;
        for(auto book: Books){
            if(book.book_id == Id[i]){
                cout<<book.title<<" by "<<book.author<<endl;
                is_find = true;
            }
        }
        if(not is_find) cout<<"Book not found"<<endl;
    }
    return 0;
}
