import java.util.*;

public class App
{
    public static void main(String[] args) throws Exception
    {
        var matrix = new Matrix(10, 15);
        int choice;

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
                choice = GetInt(in, "1. Показать матрицу\n2. Показать подматрицу\n3. Изменить размер матрицы\n4. Изменить элемент матрицы\n0. Выход");

                System.out.println();

                switch (choice)
                {
                    case 1:
                        for (int i = 0; i < matrix.Rows(); i++)
                        {
                            for (int j = 0; j < matrix.Columns(); j++)
                            {
                                System.out.print(matrix.Get(i, j));
                                System.out.print("\t");
                            }
                            System.out.println();
                        }

                        break;
                    case 2:

                        break;

                    case 3:
                        int x, y;

                        while ((x = GetInt(in, "Введите количество строк")) < 0);
                        while ((y = GetInt(in, "Введите количество столбцов")) < 0);

                        matrix.SetSize(x, y);

                        break;
                    case 4:

                        break;
                    case 0:
                        return;
                }
                
                System.out.println();
            }
        }
    }

    static int GetInt(Scanner in, String output)
    {
        int result;

        while (true)
        {
            System.out.println(output);

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
}
