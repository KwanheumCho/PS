#include <iostream>
#include <sstream>
#include <map>
using namespace std;
map<char, int> fast_chk;
map<char , int> result;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	// 원의 크기 : numOfAllPlayers -1; 
	int c_size = numOfAllPlayers-1;
	char* Circle = new char[c_size];
	
	for(int i=0; i<c_size; i++){
		Circle[i] = char('B'+(i));
	}
	result['A'] += 1;
	for(int i=0; i<numOfQuickPlayers; i++){
		fast_chk[namesOfQuickPlayers[i]] += 1;
	}
	
	//수건 놓는 위치
	int cur = 0;
	char now = 'A';
	for(int j=0; j<numOfGames; j++){
		int pos = cur+numOfMovesPerGame[j];
		if(pos >= c_size){
			pos = pos%c_size;
		}
		else if(pos < 0){
			int tmp = abs(pos)%c_size;
			pos = c_size - tmp;
		}
		cur = pos;
		// cur위치에 있던 알파벳이 빠른애인지 아닌지 확인
		if( fast_chk[Circle[cur]] == 1){ //빠른애면
			//범인 그대로이고 카운트만 증가
			result[now] += 1;
		}
		else{
			//범인 교체
			char before = now;
			now = Circle[cur];
			Circle[cur] = before;
			result[now] += 1;
		}
	} // Game for문
	for(int i=0; i<c_size; i++){
		cout << Circle[i] <<" "<<result[Circle[i]] << endl;
	}
	cout << now << " "<<result[now] << endl;
	
	
	
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}