import java.util.*;

public class App
{
    public static void main(String[] args) throws Exception
    {
        var matrix = new Matrix(10, 15);
        int choice;
        int x, y;
        
        Random random = new Random();
        
        for (int i = 0; i < matrix.Rows(); i++)
        {
            for (int j = 0; j < matrix.Columns(); j++)
            {
                matrix.Set(i, j, random.nextInt(-50, 51));
            }
        }

        try (Scanner in = new Scanner(System.in))
        {
            while (true)
            {
                choice = GetInt(in,
                "1. Показать матрицу\n" +
                "2. Показать подматрицу\n" +
                "3. Изменить размер матрицы\n" +
                "4. Изменить элемент матрицы\n" + 
                "0. Выход\n");

                System.out.println();

                switch (choice)
                {
                    case 1:
                        ShowMatrix(matrix);

                        break;
                    case 2:
                        int rows, columns;

                        System.out.println("Введите координаты верхней левой ячейки");

                        do x = GetInt(in, "Введите номер строки: ");
                        while (x < 0 || x > matrix.Rows());

                        do y = GetInt(in, "Введите номер столбца: ");
                        while (y < 0 || y > matrix.Columns());
                        
                        do rows = GetInt(in, "Введите количество строк: ");
                        while (rows < 0);
                        rows = Math.min(rows, matrix.Rows() - x);

                        do columns = GetInt(in, "Введите количество столбцов: ");
                        while (columns < 0);
                        columns = Math.min(columns, matrix.Columns() - y);

                        ShowMatrix(matrix.SubMatrix(x, y, rows, columns));

                        break;

                    case 3:

                        while ((x = GetInt(in, "Введите количество строк: ")) < 0);
                        while ((y = GetInt(in, "Введите количество столбцов: ")) < 0);

                        matrix.SetSize(x, y);

                        break;
                    case 4:

                        do x = GetInt(in, "Введите номер строки: ");
                        while (x < 0 || x > matrix.Rows());

                        do y = GetInt(in, "Введите номер столбца: ");
                        while (y < 0 || y > matrix.Columns());

                        matrix.Set(x, y, GetInt(in, "Введите новое значение: "));

                        break;
                    case 0:
                        return;
                }
                
                System.out.println();
            }
        }
    }

    private static int GetInt(Scanner in, String output)
    {
        int result;

        while (true)
        {
            System.out.print(output);

            try
            {
                result = in.nextInt();

                return result;
                
            }
            catch (Exception e)
            {
                in.nextLine();
            }
        }
    }
    
    private static void ShowMatrix(Matrix matrix)
    {
        for (int i = 0; i < matrix.Rows(); i++)
        {
            for (int j = 0; j < matrix.Columns(); j++)
            {
                System.out.print(matrix.Get(i, j));
                System.out.print("\t");
            }
            System.out.println();
        }
    }
}
