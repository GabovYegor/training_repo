#include <iostream>
#include <ctime>

int main(){
    srand(time(nullptr));
    int** mas;
    int countNode = 0;
    std::cin >> countNode;
    mas = new int*[countNode];
    for(int i = 0; i < countNode; ++i)
	mas[i] = new int[countNode];
    for(int i = 0; i < countNode; ++i)
	for(int j = 0; j < countNode; ++j)
    	    mas[i][j] = 0;		
    int edge = 0;
    std::cin >> edge;
    for(int i = 0; i < edge; ++i){
	int a = rand() % countNode;
    	int b = rand() % countNode;
	if(a == b)
	    continue;	
    	mas[a][b] = 1;
	mas[b][a] = 1;
    }
    std::cout << countNode; 
    for(int i = 0; i < countNode; ++i){
	    std::cout << std::endl;
	for(int j = 0; j < countNode; ++j)
            std::cout << mas[i][j] << " ";
    }	
}
