import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=vertcat(vertcat(horzcat(horzcat(horzcat(horzcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),matrixFromDouble(3)),matrixFromDouble(4)),matrixFromDouble(5)),matrixFromDouble(6)),horzcat(horzcat(horzcat(horzcat(horzcat(matrixFromDouble(7),matrixFromDouble(8)),matrixFromDouble(9)),matrixFromDouble(4)),matrixFromDouble(5)),matrixFromDouble(6))),horzcat(horzcat(horzcat(horzcat(horzcat(matrixFromDouble(4),matrixFromDouble(1)),matrixFromDouble(5)),matrixFromDouble(9)),matrixFromDouble(6)),matrixFromDouble(3)));
double[][] C=subsref(A,new double[][][]{matrixFromDouble(1),vertcat(horzcat(matrixFromDouble(1),matrixFromDouble(5)),horzcat(matrixFromDouble(1),matrixFromDouble(2)))});

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("C=");
printMatrix(C);
System.out.println();
}
}
