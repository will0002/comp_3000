
//Name: Will Parker
//filename: hw4.cpp
//Development Environment: vim, g++, Linux
//Compile: g++ -o hw4 hw4.cpp
//Sample usage: ./hw4
//Compiler pre-directives  #include <iostream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

bool A_alive = 0, B_alive = 0, C_alive = 0;
const int A_shot_chance = 3, B_shot_chance = 2, num_runs = 10000;
const bool TRUE = true, True = true, FALSE = false, False = false; //hopefully this will prevent some typo errors

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);

void paktc(void){

cout <<"Press any key to continue...";
cin.ignore().get();
cout <<endl <<endl;

return;
}

void test_at_least_two_alive(void){

	cout << "Unit Testing 1: Function – at_least_two_alive()\n";
	
	cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
      cout << "Case passed ...\n";

	cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
     cout << "Case passed ...\n";

	cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
      cout << "Case passed ...\n";

	cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(true == at_least_two_alive(true, true, false));
      cout << "Case passed ...\n";

        cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
        assert(false == at_least_two_alive(false, false, true));
     cout << "Case passed ...\n";

        cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
        assert(false == at_least_two_alive(false, true, false));
      cout << "Case passed ...\n";

       cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(true, false, false));
     cout << "Case passed ...\n";

        cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(false, false, false));
      cout << "Case passed ...\n";

paktc();

return;
}

void unit2_functions_test(void){ //tests aaron_shoots1

cout <<"Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n" <<"	Case 1: Bob alive, Charlie alive\n" <<"		Aaron is shooting at Charlie\n";
B_alive = true; C_alive = true;
Aaron_shoots1(B_alive,C_alive);
assert(B_alive ==true);

if(C_alive == true)
	cout <<"		Aaron missed.\n";
else
	cout <<"		Charlie is dead.\n";

cout <<"	Case 2: Bob dead, Charlie alive\n" <<"		Aaron is shooting at Charlie\n";
B_alive = false; C_alive = true;
Aaron_shoots1(B_alive,C_alive);
assert(B_alive == false);
if(C_alive == true)
	cout <<"		Aaron missed.\n";
else
	cout <<"		Charlie is dead.\n";

cout <<"	Case 3: Bob alive, Charlie dead\n" << "		Aaron is shooting at Charlie\n";
B_alive = true; C_alive = false;
Aaron_shoots1(B_alive,C_alive);
assert(C_alive == false);
if(B_alive == true)
	cout <<"		Aaron missed.\n";
else
	cout <<"		Charlie is dead.\n";
paktc();
return;}

void unit3_functions_test(void){ //tests bob_shoots

cout <<"Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n" 
<<"	Case 1: Aaron alive, Charlie alive\n" <<"		Bob is shooting at Charlie\n";
A_alive = true; C_alive = true;
Bob_shoots(A_alive,C_alive);
assert(A_alive == true);
if(C_alive == true)
        cout <<"                Bob missed.\n";
else
        cout <<"                Charlie is dead.\n";

cout <<"        Case 2: Aaron dead, Charlie alive\n" 
<<"		Bob is shooting at Charlie\n";
A_alive = false; C_alive = true;
Bob_shoots(A_alive,C_alive);
assert(A_alive == false);
if(C_alive == true)
        cout <<"                Bob missed.\n";
else
        cout <<"                Charlie is dead.\n";

cout <<"        Case 3: Aaron alive, Charlie dead\n" 
<<"		Bob is shooting at Aaron\n";
A_alive = true; C_alive = false;
Bob_shoots(A_alive,C_alive);
assert(C_alive == false);
if(A_alive == true)
        cout <<"                Bob missed.\n";
else
        cout <<"                Aaron is dead.\n";
paktc();
return;}

void unit4_functions_test(void){ //tests charlie_shoots

cout <<"Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n" 
<<"	Case 1: Aaron alive, Bob alive\n" <<"               Charlie is shooting at Bob\n";
A_alive = true; B_alive = true;
Charlie_shoots(A_alive,B_alive);
assert(A_alive == true);
if(B_alive == true)
        cout <<"error\n";
else
        cout <<"                Bob is dead.\n";

cout <<"        Case 2: Aaron dead, Bob alive\n" 
<<"		Charlie is shooting at Bob\n";
A_alive = false; B_alive = true;
Charlie_shoots(A_alive,B_alive);
assert(A_alive == false);
if(B_alive == true)
        cout <<"error\n";
else
        cout <<"                Bob is dead.\n";

cout <<"        Case 3: Aaron alive, Bob dead\n" 
<<"		Charlie is shooting at Aaron\n";
A_alive = true; B_alive = false;
Charlie_shoots(A_alive,B_alive);
assert(B_alive == false);
if(A_alive == true)
        cout <<"error\n";
else
        cout <<"                Aaron is dead.\n";
paktc();
return;}

void unit5_functions_test(void){ //tests aaro_shoots2

cout <<"Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n" 
<<"	Case 1: Bob alive, Charlie alive\n" <<"               Aaron intentionally misses his first shot\n";
B_alive = true; C_alive = true;
Aaron_shoots2(B_alive,C_alive);
assert(B_alive == true);
if(C_alive == false)
        cout <<"error\n";
else
        cout <<"                Both Bob and Charlie are alive.\n";

cout <<"        Case 2: Bob dead, Charlie alive\n" 
<<"		Aaron is shooting at Charlie\n";
B_alive = false; C_alive = true;
Aaron_shoots2(B_alive,C_alive);
assert(B_alive == false);
if(C_alive == true)
        cout <<"                Aaron missed.\n";
else
        cout <<"                Charlie is dead.\n";

cout <<"        Case 3: Bob alive, Charlie dead\n" 
<<"		Aaron is shooting at Bob\n";
B_alive = true; C_alive = false;
Aaron_shoots2(B_alive,C_alive);
assert(C_alive == false);
if(B_alive == true)
        cout <<"                Aaron missed.\n";
else
        cout <<"                Bob is dead.\n";
paktc();

return;
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive){

if((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive))
return true;

else
return false;

}
/* Input: A_alive indicates whether Aaron is alive */
/*        B_alive indicates whether Bob is alive */
/*        C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */ 
/*         otherwise return false */


void Aaron_shoots1(bool& B_alive, bool& C_alive){

if(C_alive)
C_alive = rand()%A_shot_chance != 1;
else
B_alive = rand()%A_shot_chance != 1;

return;
}
/* Strategy 1: Use call by reference
 *  * Input: B_alive indicates whether Bob alive or dead 
 *   *     C_alive indicates whether Charlie is alive or dead 
 *    * Return: Change B_alive into false if Bob is killed.  
 *     *         Change C_alive into false if Charlie is killed. 
 *     */
void Bob_shoots(bool& A_alive, bool& C_alive){

if(C_alive)
C_alive = rand()%B_shot_chance != 1;
else
A_alive = rand()%B_shot_chance != 1;

return;
}
/* Call by reference
 *  * Input: A_alive indicates if Aaron is alive or dead 
 *   *     C_alive indicates whether Charlie is alive or dead 
 *    * Return: Change A_alive into false if Aaron is killed.  
 *     *         Change C_alive into false if Charlie is killed. 
 *     */
void Charlie_shoots(bool& A_alive, bool& B_alive){

if(B_alive)
B_alive = false;
else 
A_alive = false;

return;
}
/* Call by reference
 *  * Input: A_alive indicates if Aaron is alive or dead 
 *   *     B_alive indicates whether Bob is alive or dead 
 *    * Return: Change A_alive into false if Aaron is killed.  
 *     *         Change B_alive into false if Bob is killed. 
 *     */
void Aaron_shoots2(bool& B_alive, bool& C_alive){

if((B_alive == true) && (C_alive == true))
return;

if(C_alive)
C_alive = rand()%A_shot_chance != 1;
else
B_alive = rand()%A_shot_chance != 1;

return;
}
/* Strategy 2: Use call by reference
 *  * Input: B_alive indicates whether Bob alive or dead 
 *   *     C_alive indicates whether Charlie is alive or dead 
 *    * Return: Change B_alive into false if Bob is killed.  
 *     *         Change C_alive into false if Charlie is killed. 
 *     */


int main (){

srand(time(0));

cout << "*** Welcome to Will Parker’s Duel Simulator ***\n";
test_at_least_two_alive();
unit2_functions_test();
unit3_functions_test();
unit4_functions_test();
unit5_functions_test();

double AWins = 0;
double BWins = 0;
double CWins = 0;

double strat1;
double strat2;

int i = 0;

cout <<"Ready to test strategy 1 (run " <<num_runs <<" times):\n";
paktc();

cout <<". . .\n. . .\n. . .\n\n";

while(i < num_runs){

i++;
A_alive = true;
B_alive = true;
C_alive = true;

while(at_least_two_alive(A_alive,B_alive,C_alive)){

if(A_alive == true)
        Aaron_shoots1(B_alive,C_alive);
if(B_alive == true)
        Bob_shoots(A_alive,C_alive);

if(C_alive == true)
	Charlie_shoots(A_alive,B_alive);

}

if(A_alive == true)
	AWins++;
if(B_alive == true)
	BWins++;
if(C_alive == true)
	CWins++;

}

strat1 = 100*AWins/num_runs;

cout <<"Aaron won " <<AWins <<"/" <<num_runs <<" duels or " <<strat1 <<"%" <<endl;

cout <<"Bob won " <<BWins <<"/" <<num_runs <<" duels or " << 100*BWins/num_runs <<
"%" <<endl;

cout <<"Charlie won " <<CWins <<"/" <<num_runs <<" duels or " << 100*CWins/num_runs <<"%" <<endl <<endl; 

AWins = 0;
BWins = 0;
CWins = 0;

i = 0;

cout <<"Ready to test strategy 2 (run " <<num_runs <<" times):\n";
paktc();

cout <<". . .\n. . .\n. . .\n\n";

while(i < num_runs){

i++;
A_alive = true;
B_alive = true;
C_alive = true;

while(at_least_two_alive(A_alive,B_alive,C_alive)){

if(A_alive == true)
        Aaron_shoots2(B_alive,C_alive);
if(B_alive == true)
        Bob_shoots(A_alive,C_alive);

if(C_alive == true)
        Charlie_shoots(A_alive,B_alive);

}

if(A_alive == true)
        AWins++;
if(B_alive == true)
        BWins++;
if(C_alive == true)
        CWins++;

}

strat2 = 100*AWins/num_runs;

cout <<"Aaron won " <<AWins <<"/" <<num_runs <<" duels or " <<strat2 <<"%" <<endl;

cout <<"Bob won " <<BWins <<"/" <<num_runs <<" duels or " << 100*BWins/num_runs <<
"%" <<endl;

cout <<"Charlie won " <<CWins <<"/" <<num_runs <<" duels or " << 100*CWins/num_runs <<"%" <<endl <<endl;

if (strat1 > strat2)
	cout <<"Strategy 1 is better than strategy 2." <<endl <<endl;
else
	cout << "Strategy 2 is better than strategy 1." <<endl <<endl;


return 0;
}

