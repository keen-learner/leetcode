/*
// https://leetcode.com/articles/shortest-distance-in-a-line/

Table point holds the x coordinate of some points on x-axis in a plane, which are all integers.
Write a query to find the shortest distance between two points in these points.
| x   |
|-----|
| -1  |
| 0   |
| 2   |
The shortest distance is '1' obviously, which is from point '-1' to '0'. So the output is as below:
| shortest|
|---------|
| 1       |
Note: Every point is unique, which means there is no duplicates in table point.
Follow-up: What if all these points have an id and are arranged from the left most to the right most of x axis?

*/


-- Method 1
SELECT
    MIN(ABS(p1.x - p2.x)) AS shortest
FROM
    point p1
        JOIN
    point p2 ON p1.x != p2.x;

-- METHOD 2
SELECT
    MIN(p2.x - p1.x) AS shortest
FROM
    point p1
        JOIN
    point p2 ON p1.x < p2.x ;

-- METHOD 3
SELECT MIN(P1.x - P2.x) AS shortest 
FROM (SELECT @id1:=0, @id2:=0) AS t,
     (SELECT @id1:=@id1+1 AS id, x FROM point ORDER BY x) AS P1
     JOIN
     (SELECT @id2:=@id2+1 AS id, x FROM point ORDER BY x) AS P2
     ON P1.id = P2.id + 1
WHERE P1.id > 1;

-- METHOD 4
SET @prev := -100000000; 
SELECT MIN(diff) AS shortest
FROM (SELECT (x - @prev) AS diff, @prev := x 
      FROM (SELECT * 
            FROM point 
            ORDER BY x) AS t1
     ) AS t2 ;


