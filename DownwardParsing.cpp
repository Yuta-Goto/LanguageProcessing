#include <iostream>
using namespace std;

char token;
const char SYM_PLUS = '+';
const char SYM_MULT = '*';
const char SYM_LEFTPAR = '(';
const char SYM_RIGHTPAR = ')';

void E();
void T();
void F();
void error();

int main(){
    E();
    return 0;
}




void E(){
    T();//とりあえずT読む
    while(token == SYM_PLUS){//+だったらT読もうね。
        token = getchar();
        T();
    }
}

void T(){
    F();//とりあえずF読む
    while(token == SYM_MULT){//掛け算だったらF読もうね。
        token = getchar();
        F();
    }
}


void F(){
    if(token == SYM_LEFTPAR){// ( 
        token = getchar();
        E();
        if(token == SYM_RIGHTPAR){//  )
            token = getchar();
        }else{//   (　で始まって、一回E呼んだんだからなんやかんやでEから戻ってきたときには ) になってるはず。そうじゃないってことはエラー。
            error();
        }
    }else if(token == '1'){//＜数字＞か＜名前＞なら
        token = getchar();
        cout<<"ok"<<endl;
    }else{//　(　でも　＜数字＞＜名前＞でもないものはFじゃねえ！！！
        error();
    }
}


void error(){
    cout<<"Error"<<endl;
    return;
}