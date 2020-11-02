#include <iostream>
#include <sstream>

using namespace std;

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	int* height = new int[width]{0,};
	int result = 0;
	for(int i=0; i<day; i++){
		for(int j=0; j<width; j++){
			height[j] += blocks[i][j];
		}
		//이제 높이비교!
		int left = height[0]; //left 기준
		int before = -1;
		int right = 0; // right 기준
		int cnt = 0;
		bool flag = false;
		//int gap=0;
		for(int j=1; j<width-1; j++){
			right = height[j];
			if(left > right){ // left 기준이 더 큰 경우
				if(right < height[j+1]){
					//더하고 계속
					cnt++;
					result += (left-right);
					height[j] += (left-right);
				}
				else{
					// 스탑하고 gap만큼 빼줘
					result -= (left-right)*cnt;
					for(int k=cnt; k>0; k--){
						height[j-k] -= (left-right);
					}
					cnt = 0;
					left = right;
					cout <<"width: "<< j <<" "<< left <<" "<< right << endl;
				}
			}
			else{
				//result -= (right-left)*cnt;
				cnt = 0;
				left = right;
			}
			//cout << result << " " << left << " " <<right <<" " <<cnt << endl;
		} // for width;
		//마지막 체크
		if(left > height[width-1]){
			//cout << result << " " << left << " " <<right <<" " <<cnt << endl;
			result -= (left-height[width-1])*cnt;
			for(int k=cnt; k>0; k--){
						height[width-1-k] -= (left-height[width-1]);
					}
		}
		for(int a=0; a<width; a++){
			cout << height[a]<< " ";
		}
		cout << endl;
		//cout << "day" << i << " "<<result << endl;
	}// for day
	//cout << result << endl;
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}