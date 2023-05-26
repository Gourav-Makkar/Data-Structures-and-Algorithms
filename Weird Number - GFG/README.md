# Weird Number
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a number N check whether it&nbsp;is wierd or not. A&nbsp;number is weird if the sum of the proper divisors&nbsp;(divisors including 1 but not itself) of the number is greater than the number, but no subset&nbsp;of those divisors sums to the number itself.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 70
<strong>Output: </strong>1
<strong>Explanation: </strong>The smallest weird number 
is 70. Its proper divisors are 1, 2, 5, 
7, 10, 14, and 35; these sum to 74, but 
no subset of these sums to 70. </span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 12
<strong>Output: </strong>0
<strong>Explanation: </strong>The number 12, for example,
is not&nbsp;weird, because the proper divisors 
of 12 are 1, 2, 3, 4, and 6, sum of 
divisors is 16; but there is a subset 
{2, 4, 6} with sum 12, i.e., 2+4+6 = 12.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anything. Your task is to complete the function&nbsp;<strong>is_weird()</strong>&nbsp;which takes n as input parameter and returns 1 if the number is weird number otherwise returns 0.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10000</span></p>
</div>