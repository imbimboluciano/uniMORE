package oop.Jdbc.SimpleDB;

import oop.Utils.DBManager;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class OperationDB {

    Statement statement;

    public OperationDB() throws SQLException {

        MySQLConnection();

        testDB();

        System.out.println("\nTest Select...");
        testSelect();

        System.out.println("\nTest Update...");
        testUpdate();
        testSelect();

        System.out.println("\nTest Scrollable...");
        testScrollable();

        System.out.println("\nTest Updatable...");
        testUpdateable();
        testSelect();


        System.out.println("\nTest Updatable...");
        testSensitive();


        closeDB();
    }


    public void MySQLConnection() throws SQLException {
        DBManager.setConnection(DBManager.JDBC_Driver_MySQL,DBManager.JDBC_URL_MySQL); //inizializzo il tipo di database
        statement = DBManager.getConnection().createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDATABLE); //chiedo la connessione e creo uno statement per le operazioni
    }

    public void testDB() throws SQLException{

        try{

            statement.executeQuery("SELECT * FROM book LIMIT 1");
        }catch (SQLException e){
            statement.executeUpdate("DROP TABLE IF EXISTS book");
            statement.executeUpdate("CREATE TABLE book (id INTEGER PRIMARY KEY, title VARCHAR(30), author VARCHAR(30), pages INTEGER)");
            statement.executeUpdate(
                    "INSERT INTO book (id, title, author, pages) VALUES(1, 'The Lord of the Rings', 'Tolkien', 241)");
            statement.executeUpdate(
                    "INSERT INTO book (id, title, author, pages) VALUES(2, 'Fight Club', 'Palahniuk', 212)");
            statement.executeUpdate(
                    "INSERT INTO book (id, title, author, pages) VALUES(3, 'Computer Networks', 'Tanenbaum', 313)");
            statement.executeUpdate(
                    "INSERT INTO book (id, title, author, pages) VALUES(4, 'Affective Computing', 'Picard', 127)");
        }


    }

    public void testSelect() throws SQLException{
        ResultSet rs = statement.executeQuery("SELECT * FROM book");
        while (rs.next()){
           // System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getString(3) + " " + rs.getInt(4));
            System.out.println(rowToString(rs));
        }
    }

    public void testUpdate() throws SQLException {
        statement.executeUpdate(
                "UPDATE book SET pages=176 WHERE id=1");
        statement.executeUpdate(
                "UPDATE book SET pages=99 WHERE id=3");
    }

    public void testScrollable() throws SQLException {
        ResultSet rs = statement.executeQuery("SELECT * FROM book LIMIT 100 OFFSET 0");
        // Second record
        rs.absolute(2); //parte da 1 e non da 0
        System.out.println(rowToString(rs));

        // Previous record
        rs.previous();
        System.out.println(rowToString(rs));

        // +2 records from current position
        rs.relative(3);
        System.out.println(rowToString(rs));
    }

    public void testUpdateable() throws SQLException {
        ResultSet rs = statement.executeQuery("SELECT * FROM book LIMIT 100 OFFSET 0");
        while (rs.next()) {
            int pages = rs.getInt("pages");
            rs.updateInt("pages", pages + 10);
            rs.updateRow();
            rs.updateInt("pages",rs.getInt("pages") + 1);
            rs.updateRow(); //serve per aggiornare il database
        }
    }

    public void testSensitive() throws SQLException {
        ResultSet rs = statement.executeQuery("SELECT * FROM book LIMIT 100 OFFSET 0");
        for (int retry = 0; retry < 10; retry++) {
            System.out.printf("\n[%d] awaiting for external changes 10s...\n", retry);
            rs.beforeFirst();
            while (rs.next()) {
                rs.refreshRow();
                System.out.println(rowToString(rs));
            }

            try {
                Thread.sleep(10000);
            } catch (InterruptedException ignored) {}
        }
    }

    public void closeDB() throws SQLException{
        DBManager.close();
    }


    public String rowToString(ResultSet rs) throws SQLException {
        return String.format("id=%d, title=%s, author=%s, pages=%d",
                rs.getInt("id"),
                rs.getString("title"),
                rs.getString("author"),
                rs.getInt("pages"));
    }








}
