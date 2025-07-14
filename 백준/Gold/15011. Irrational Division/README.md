# [Gold II] Irrational Division - 15011 

[문제 링크](https://www.acmicpc.net/problem/15011) 

### 성능 요약

메모리: 2120 KB, 시간: 0 ms

### 분류

많은 조건 분기, 다이나믹 프로그래밍, 게임 이론, 그리디 알고리즘

### 제출 일자

2025년 7월 14일 22:31:00

### 문제 설명

<p>Your family has been blessed with chocolate! A huge piece of chocolate has been given to you and your sister to share. However, as you gobbled up the large majority last time, your parents have invented a game to keep things fair (and to keep you occupied while they hide all the other chocolate). To keep things interesting, they have given you a rectangular piece of chocolate, which consists of little squares of both dark chocolate and white chocolate in a chessboard pattern. While you and your sister both love dark chocolate, you hate white chocolate! So, both you and your sister want as much dark chocolate as possible, while simultaneously obtaining as little white chocolate as possible. Every dark piece of chocolate you obtain gives you 1 meaningless unit of happiness, while a white piece lowers your happiness by 1 meaningless unit (and the same holds for your sister). Now, while you love your sister very much, there is always heavy competition between siblings, so your goal is to maximize the difference of your obtained happiness and her obtained happiness (while she tries to do the opposite, obviously).</p>

<p>The game works as follows. Your parents place a p×q-rectangle of the aforementioned mixed chocolate on a table. You are situated on the west side of the table and your sister on the south side. The side of length p is parallel to the north-south line, while the side of length q is parallel to the east-west line. Furthermore, the north-west square is made of dark chocolate. Then, starting with yourself, you take turns breaking off blocks of chocolate (which you can keep). You can break off any positive number of entire columns from the west side, while your sister breaks off any positive number of entire rows from the south side. You repeat this process until no more chocolate is left. Your sister is very smart and will always play the game perfectly.</p>

<p>A game might proceed like this, for example: you and your sister start with a 3 ×4-rectangle. You decide to break off 2 columns, obtaining 3 dark and 3 white chocolate squares, netting a happiness of zero. Your sister then breaks off 1 row, obtaining 1 dark and 1 white squares as well, so no happiness for her either. You then take a single column, which nets you nothing again, after which your sister decides to break off one row, which nets her 1 happiness! You then take the last piece, which makes you lose a unit of happiness, so your total score is −1 − 1 = −2. See the figure. (Note: the strategies used here might not be optimal.)</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15011/1.png" style="height:163px; width:201px"></p>

<p style="text-align: center;">Figure 5: The example game described in the problem statement.</p>

### 입력 

 <p>Given are two positive integers p and q, both at most 100, the height and width of the chocolate rectangle.</p>

### 출력 

 <p>Output the largest possible difference (in your favour) between your net happiness and your sister’s net happiness.</p>

