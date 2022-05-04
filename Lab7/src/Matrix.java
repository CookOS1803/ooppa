import java.util.*;

public class Matrix
{
    private ArrayList<ArrayList<Integer>> matrix;

    public Matrix(int x, int y)
    {
        matrix = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < x; i++)
        {
            var arrayList = new ArrayList<Integer>();

            for (int j = 0; j < y; j++)
            {
                arrayList.add(0);
            }

            matrix.add(arrayList);
        }

    }

    public int Get(int x, int y)
    {
        return matrix.get(x).get(y);
    }

    public void Set(int x, int y, int value)
    {
        matrix.get(x).set(y, value);
    }

    public int Rows()
    {
        return matrix.size();
    }

    public int Columns()
    {
        if (matrix.size() == 0)
            return 0;
        else
            return matrix.get(0).size();
    }

    public void SetSize(int x, int y)
    {
        var newMatrix = new Matrix(x, y);

        for (int i = 0; i < Rows() && i < x; i++)
        {
            for (int j = 0; j < Columns() && j < y; j++)
            {
                newMatrix.Set(i, j, Get(i, j));
            }
        }

        matrix = newMatrix.matrix;
    }

    public Matrix SubMatrix(int x, int y, int rows, int columns)
    {
        var result = new Matrix(rows, columns);

        for (int i = 0; i < result.Rows(); i++)
        {
            for (int j = 0; j < result.Columns(); j++)
            {
                result.Set(i, j, Get(i + x, j + y));
            }
        }

        return result;
    }

}
