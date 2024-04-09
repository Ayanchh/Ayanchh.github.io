#include <iostream>
#include <string>
#include <array>

std::array<char, 10> square;

void show_table(){
    std::cout<<"-------------\n| "
    << square[1] <<" | "<< square[2] <<" | "<< square[3] 
    <<" | \n-------------\n| "
    << square[4] <<" | "<< square[5] <<" | "<< square[6] 
    <<" |\n-------------\n| "
    << square[7] <<" | "<< square[8] <<" | "<< square[9] 
    <<" |\n-------------";
}

bool check_win(){
    if (square[1] == 'O' or square[1] == 'X'){
        if (square[1] == square[2] && square[2] == square[3])
            return 1;
        else if (square[1] == square[4] && square[4] == square[7])
            return 1;
        else if (square[1] == square[5] && square[5] == square[9])
            return 1;
    }
    if (square[5] == 'O' or square[5] == 'X'){
        if (square[2] == square[5] && square[5] == square[8])
            return 1;
        else if (square[3] == square[5] && square[5] == square[7])
            return 1;
        else if (square[4] == square[5] && square[5] == square[6])
            return 1;
    }
    if (square[9] == 'O' or square[9] == 'X'){
        if (square[3] == square[6] && square[6] == square[9])
            return 1;
        else if (square[7] == square[8] && square[8] == square[9])
            return 1;
        else if (square[7] == square[8] && square[8] == square[9])
            return 1;
    }
    return 0;
}

int main() {
    char play = 'y', plr, opp_plr;
    int turn, cnt;
    while(play == 'y'){
        square = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        plr = 's', opp_plr = 's';
        while(plr != 'X' & plr != 'O'){
            std::cout<<"Choose your side:(X or O)\n";
            std::cin>>plr;
            if (plr == 'X'){
                opp_plr = 'O';
            }else if(plr == 'O'){
                opp_plr = 'X';
            }else{
                std::cout<<"Wrong! Try Again\n";
            }
        }
        cnt = 0;
        while(true){
            system("clear");
            std::cout<<"\n------"<<plr<<"------\n";
            show_table();
            turn = -2;
            while (turn<1 or turn > 9 or square[turn] == 'X' or square[turn] == 'O'){
                std::cout<<"\nWhat is your turn?(1 to 9)\n";
                std::cin>>turn;
            }
            square[turn] = plr;
            turn = 10;
            if (check_win()){
                std::cout<<"Player 1 won!\n";
                break;
            }
            cnt++;
            if (cnt == 9){
                show_table();
                std::cout<<"\nIt's a Draw!\n";
                break;
            }
            system("clear");
            std::cout<<"------"<<opp_plr<<"------\n";
            show_table();
            while (turn<1 or turn > 9 or square[turn] == 'X' or square[turn] == 'O'){
                std::cout<<"\nWhat is the opponent's turn?(1 to 9)\n";
                std::cin>>turn;
            }
            cnt++;
            square[turn] = opp_plr;
            turn = 10;
            if (check_win()){
               std::cout<<"Player 2 won!\n";
                break;
            }
        }
        std::cout<<"Do you want to play again?(y/n)\n";
        std::cin>>play;
    }
    std::cout<<"Thank you for playing this game\n";
    return 0;
}