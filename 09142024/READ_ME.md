My solutions to JV/Guest practice contest of 09/14/2024 for the UCF programming team. Was not able to attend in person sadly in saturday.
Tried to mimic the practice contest; gave my self 5 hour timer but paused timer for various breaks. Solved problems w/ java docs as reference.

----------------------------------------------------------------
Times:
a - 1:05
c - 1:13
d - 1:24
g - 1:30
i - 2:03
e - 3:04
b - 4:25
----------------------------------------------------------------
On problem A no major notes, just took a while to work through. Should've dumped the problem for later for penalty point reduction.

On problem B there were additional time saves I had to implement, didnt take significant time though.

No notes for problem C, straightforward.

On problem D it was just an attention to detail problem. Should've taken 5-7 less minutes but I just mistyped 00:0 instead of 0:00. Brain woudln't parse the error. 


On problem D I should've taken longer in analyzing the problem. Started with an incorrect/tricky approach of storing times as long string, was just incredibly flawed approach that breaks down for any time > 9. Would have to convert them to some sort of object that is sorted, which treeMaps make redundant. After realizing this I shouldve paused longer and written out the solution, as my second approach was just inefficient, can't remember it exactly but it had TreeSets as well and was redundant.

Looked at problem f, regretted life choices, did not attempt.

No notes for problem g, straightforward.

On problem h, I attempted a brute force solution, knowing that it was going to TLE. Knew the problem was going to have to do w/ prime factorization but blanked on the process and exponent rule where (x + y)^b = x^b + y^b. Also just would not have thought of using stars and bars to allocate the triplets. Brute force resulted in TLE as expected. After contest, plugged it into ChatGPT o1-preview and it gave me the exponent and star and bar approach. GPT starting ranting about fermats little rabbit hole, ignored it and it worked sooo ¯\_(ツ)_/¯

On problem i, approach was correct, just missed a sneaky edge case where a large number of soldiers can be obtained w/ selecting less than k territories, only staggered me for about 5 minutes, so no big time loss. Example:
k = 3, n = 5
n: 1, 2 , 3, 1000, 5
We'd like to have the 1000 man territory of course, but since we must select EXACTLY 3, non-adjacent, territories, we cannot select it, as we wont be able to select territory 3 or 5 (adjacent to 1000), and can only select 1 or 2, as they're adjacent, resulting in a maximum from 2 selections instead of the mandatory 3.

On problem j, I ran out of time to complete due to wasting on problem h. Looks like a dp problem, but seems quite tricky and convoluted, would not be able to code in the 30. Will attempt soon.