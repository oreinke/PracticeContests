Much rougher problem sets with alot of graph problems and DS type questions.
Was very sick and competed from home, so that definitely didn't help, but still performed extremely poorly.
f - 22
i - 37
h - 1:35
-------------------------------------------------------------------------------------------------------
Main problem (besides sickness) was flipping between problems too quickly.
Instead of coding, should've thought through the problems further and validated my approach.
Spent way too long on prob a when I knew my approach was invalid. Started on problem C and spun wheels for no reason,
when it was most likely the most complicated problem if thought through throughly. Missed how groups may be independent.
-------------------------------------------------------------------------------------------------------
C, catina of babel
Given a population of <= 100 persons, where each person speaks one language and can understand that language along with an optional list of more langauges.
We Must find the minimum number of people to remove from the catina so all members can communicate.
First we must treat each member as a vertex. Each vertex has one and only one spoken language. Draw weighted edges for every vertex, by drawing an edge to every vertex that understands the vertex's spoken language. Do not draw an edge to itself, we are not accounting for schizophrenia. Conduct n dfs searches, using each vertex as a root. mark nodes that you will go to as visited, not node that we are currently in. This prevents us from marking root as visited, it must be cycled back to. for each node we visit, we first conduct a dfs for the root. If root isnt reachable, dont consider any connected nodes. If it is, add curNode to valid members. After this is done, only nodes that are connected to the root and can reach the root will be in valid members (this applies to the root itself aswell). If this is the largest valid member size found so far, record it. original - largest size will be our answer. (unless largest == 0, then our answer is original -1).
Apparently this is actually a strongly connected component question, but I didn't have to change my approach, will look into these algos later.
-------------------------------------------------------------------------------------------------------
A, all about that base
Not too difficult, just had some annoyance with errors sick me made (just didnt count right). Need to use the proper (char) (char + int) strategy next time. Forgot to account for unary not having the 0 char.
-------------------------------------------------------------------------------------------------------
B, Bobbys wager 
No problems. Test of binomial probabilities. Just make sure to read the exact output constraints carefully
-------------------------------------------------------------------------------------------------------
D, Circuit Counting
Got stuck on this one, couldn't think of a solution with feasible runtime, only 2^40. Ran it through o1. Solution is called Meet in the middle. we divide the vectors into 2 subsets, resulting in 2^20 * 2 + the time to add vectors from each set, which is all negligible compared to 2^40.
This ended up just not working. Solution is likely correct but i was just missing some edgecase or had a logic error. DP is a much easier approach, where we start a dp recursion with 0 sum for x and y, and 0 for step. We then increase step by 1 and do a call including and not including cur vector, moving on to next step. If same step and sums call made before, just add val already found from memo. if step == N, ret 1 if sums 0, 0 otherwise
