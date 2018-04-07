/*

// https://leetcode.com/articles/find-customer-referee/

Given a table customer holding customers information and the referee.

+------+------+-----------+
| id   | name | referee_id|
+------+------+-----------+
|    1 | Will |      NULL |
|    2 | Jane |      NULL |
|    3 | Alex |         2 |
|    4 | Bill |      NULL |
|    5 | Zack |         1 |
|    6 | Mark |         2 |
+------+------+-----------+
Write a query to return the list of customers NOT referred by the person with id '2'.

For the sample data above, the result is:

+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+

*/

SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;

/*
EXPLAIN:

Intuition

Some people come out the following solution by intuition.

SELECT name FROM customer WHERE referee_Id <> 2;
However, this query will only return one result:Zack although there are 4 customers not referred by Jane (including Jane herself). All the customers who were referred by nobody at all (NULL value in the referee_id column) don’t show up. But why?

Algorithm

MySQL uses three-valued logic -- TRUE, FALSE and UNKNOWN. Anything compared to NULL evaluates to the third value: UNKNOWN. That “anything” includes NULL itself! That’s why MySQL provides the IS NULL and IS NOT NULL operators to specifically check for NULL.

Thus, one more condition 'referee_id IS NULL' should be added to the WHERE clause as below.

MySQL

SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;
or

SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;

Tips

The following solution is also wrong for the same reason as mentioned above. The key is to always use IS NULL or IS NOT NULL operators to specifically check for NULL value.

SELECT name FROM customer WHERE referee_id = NULL OR referee_id <> 2;


*/
