import sqlite3 as lite

con = lite.connect('test.db')

with con:

    cur = con.cursor()
    cur.execute("SELECT * FROM car")

    rows = cur.fetchall()

    for row in rows:
        print (row)

