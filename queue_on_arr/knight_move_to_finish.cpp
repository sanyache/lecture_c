#include<iostream>

using namespace std;


void push_queue(int Q[], int &tail, int el){

    Q[tail++] = el;
}

int pop_queue(int Q[], int & head){
    return Q[head++];
}

bool is_empty_queue(int head, int tail){
    return head == tail;
}

int main(){
    int Q[64];
    int head=0;
    int tail=0;
    //можливі варіанти переходів конем
    int moves[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    //шахова дошка. спочатку всі клітинки false; якщо відвідали, то true
    bool board[8][8];
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            board[i][j] = false;

    int start, finish;
    int counter = 0;
    cin>>start;
    cin>>finish;
    push_queue(Q, tail, start);
    int capacity_level = 1; // кількість елементів на рівні level
    int level=0;
    //поки черга не порожня
    while(not is_empty_queue(head, tail)){
        int current = pop_queue(Q, head);
        if(current == finish) break;

        //номер клітинки на цифри
        int x = current/10;
        int y = current%10;
        counter = 0;
        //перевіряємо можливі шляхи з поточної клітинки , всього 8
        for(int i=0; i<8; i++){
            //координата нової клітинки
            int dx = x + moves[i][0];
            int dy = y + moves[i][1];
            int xy = dx*10 + dy;
            //якщо цей варіант не виходить за межі дошки
            if(dx>= 0 and dx <= 7 and dy >= 0 and dy <= 7){
                 //якщо варіант не розглядався раніше
                if(board[dx][dy] == false){
                    push_queue(Q, tail, xy);
                    board[dx][dy] = true;
                    counter ++;
                }
            }
        }
        //capacity_level --; // зменьшуємо к-сть елементів у рівні level
        //if(capacity_level == 0){   // якщо вичерпали всі елементи р рівня level, переходимо на новий ріверь і обчислюємо нову к-сть на новому рівні.
          //  capacity_level = tail - head;
            //level ++;
            level++;


        cout<<level<<'\n';

    }

    cout<<level;
    return 0;
}
