<h2><a href="https://leetcode.com/problems/customers-who-never-order/solution/">183. Customers Who Never Order</a></h2><h3>Easy</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code>Customers</code></p>

<pre style="position: relative;">+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
In SQL, id is the primary key column for this table.
Each row of this table indicates the ID and name of a customer.
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p>&nbsp;</p>

<p>Table: <code>Orders</code></p>

<pre style="position: relative;">+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
In SQL, id is the primary key column for this table.
customerId is a foreign key (join key in Pandas) of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p>&nbsp;</p>

<p>Find all customers who never order anything.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre style="position: relative;"><strong>Input:</strong> 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
<strong>Output:</strong> 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>
</div>