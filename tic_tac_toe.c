#include &lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include &lt;ctype.h&gt;
#include &lt;time.h&gt;
char board[3][3];
const char PLAYER1 = &#39;X&#39;;
const char PLAYER2 = &#39;O&#39;;
void reset();
void printboard();
int checkfreespace();
void p1move();
void p2move();
char checkwinner();
void printwinner(char);
int main(){
char winner = &#39; &#39;;
char response;
do
{
    winner=&#39; &#39;;
    response=&#39; &#39;;
    reset();
while(winner == &#39; &#39; &amp;&amp; checkfreespace())
{
  printboard();
  p1move();
  winner = checkwinner();
  if(winner!= &#39; &#39; || checkfreespace()==0){
    break;
  }
   p2move();
  winner = checkwinner();
  if(winner!= &#39; &#39; || checkfreespace()==0){
    break;
  }
}
printboard();
printwinner(winner);
printf(&quot;\n Would you like to play again? (Y/N)&quot;);

scanf(&quot;%c&quot;);
scanf(&quot;%c&quot;,&amp;response);
response = toupper(response);
} while (response==&#39;Y&#39;);

return 0;
}

void reset(){
for(int i=0;i&lt;3;i++){
    for(int j=0;j&lt;3;j++){
      board[i][j]= &#39; &#39;;
    }
}
}

void printboard(){
printf(&quot;%c | %c | %c &quot;, board[0][0], board[0][1], board[0][2]);
printf(&quot;\n--|---|--\n&quot;);
printf(&quot;%c | %c | %c &quot;, board[1][0], board[1][1], board[1][2]);
printf(&quot;\n--|---|--\n&quot;);
printf(&quot;%c | %c | %c &quot;, board[2][0], board[2][1], board[2][2]);
printf(&quot;\n&quot;);
}

int checkfreespace(){
   int fspace = 9;
   for(int i=0 ;i&lt;3; i++){
     for(int j=0 ;j&lt;3; j++){
    if(board[i][j]!= &#39; &#39;)
    {
      fspace--;
    }
   }
   }
   return fspace;
}
void p1move(){
int x;
int y;
do
{
    printf(&quot;\nPLAYER1&#39;S TURN:\n&quot;);
printf(&quot;\nEnter the row #(1-3)\n&quot;);

scanf(&quot;%d&quot;, &amp;x);
x--;
printf(&quot;\nEnter the column #(1-3)\n&quot;);
scanf(&quot;%d&quot;, &amp;y);
y--;
if(board[x][y]!= &#39; &#39;){
    printf(&quot;\nINVALID MOVE!\n&quot;);
}
else{
board[x][y] = PLAYER1;
break;
}
 } while (board[x][y]!= &#39; &#39;);
}
void p2move(){
int x;
int y;
do
{
     printf(&quot;\nPLAYER2&#39;S TURN:\n&quot;);
printf(&quot;\nEnter the row #(1-3):\n&quot;);
scanf(&quot;%d&quot;, &amp;x);
x--;
printf(&quot;\nEnter the column #(1-3):\n&quot;);
scanf(&quot;%d&quot;, &amp;y);
y--;
if(board[x][y]!= &#39; &#39;){
    printf(&quot;\nINVALID MOVE!\n&quot;);
}
else{
board[x][y] = PLAYER2;
break;
}
 } while (board[x][y]!= &#39; &#39;);
}

char checkwinner(){
for(int i=0;i&lt;3;i++){
    if (board[i][0] == board[i][1] &amp;&amp; board[i][0] == board[i][2])
    {
       return board[i][0];
    }  
}
for(int i=0;i&lt;3;i++){
    if (board[0][i] == board[1][i] &amp;&amp; board[0][i] == board[2][i])
    {

       return board[0][i];
    }  
}
if (board[0][0] == board[1][1] &amp;&amp; board[0][0] == board[2][2])
    {
       return board[0][0];
    }  
    if (board[0][2] == board[1][1] &amp;&amp; board[0][2] == board[2][0])
    {
       return board[0][2];
    }
    return&#39; &#39;;
}
void printwinner(char winner){
if(winner == PLAYER1){
    printf(&quot;\nPLAYER1 WINS!\n&quot;);
}
else if(winner == PLAYER1){
    printf(&quot;\nPLAYER2 WINS!\n&quot;);
}
else{
    printf(&quot;\nIT&#39;S A DRAW!\n&quot;);
}
}
