import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=vertcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),horzcat(matrixFromDouble(3),matrixFromDouble(4)));
subsasgn(A,new double[][][]{vertcat(matrixFromDouble(1),matrixFromDouble(2))},horzcat(matrixFromDouble(5),matrixFromDouble(7)));

System.out.println("A=");
printMatrix(A);
System.out.println();
}
}
