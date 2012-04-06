import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=vertcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),horzcat(matrixFromDouble(7),matrixFromDouble(8)));
double[][] B=vertcat(horzcat(matrixFromDouble(7),matrixFromDouble(8)),horzcat(matrixFromDouble(4),matrixFromDouble(6)));
double[][] C=mldivide(A,B);

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("B=");
printMatrix(B);
System.out.println();
System.out.println("C=");
printMatrix(C);
System.out.println();
}
}
