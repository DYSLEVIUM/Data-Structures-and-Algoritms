# Write your MySQL query statement below
# backtics give me a hard time
SELECT `Score`, DENSE_RANK() OVER (ORDER BY `Score` DESC) `Rank` FROM `Scores`;
