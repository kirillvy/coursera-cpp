#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
ADD i s
Назначить дело с названием s на день i текущего месяца.

DUMP i
Вывести все дела, запланированные на день i текущего месяца.

NEXT
Перейти к списку дел на новый месяц. При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и становится активным
 (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. После выполнения данной команды новый список дел и 
 следующий месяц становятся текущими, а работа со старым списком дел прекращается. При переходе к новому месяцу необходимо обратить внимание на разное 
 количество дней в месяцах:

если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.
Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. Более того, при создании списка дел на следующий месяц, 
он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.

12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 28
 * */



int main() {
  vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int curMonth = 0;

  vector<vector<string>> todo(31, vector<string>(0));
  string command, task;
  int i;

  int c;
  cin >> c;

  while (c--) {
    cin >> command;
    if(command == "NEXT") {
      int nextMonth = curMonth + 1;
      if (nextMonth == 12) {
        nextMonth = 0;
      }
      vector<vector<string>> newTodo = todo;
      newTodo.resize(months[nextMonth], vector<string>(0));
      if (months[nextMonth] < months[curMonth]) {
        int lastDay = months[nextMonth] -1;
        for (int i = lastDay + 1; i < months[curMonth]; ++i){
          newTodo[lastDay].insert(end(newTodo[lastDay]), begin(todo[i]), end(todo[i]));
        }
      }
      todo = newTodo;
      curMonth = nextMonth;
    } else if (command == "DUMP") {
      cin >> i;
      cout << todo[i-1].size();
      for (auto c: todo[i-1]) {
        cout << " " << c;
      }
      cout << endl;
    } else if (command == "ADD") {
      cin >> i >> task;
      todo[i-1].push_back(task);
    }
  }


  return 0;
}
