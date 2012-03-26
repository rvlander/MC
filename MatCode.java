import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(10));
double[][] B=colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(2));
double[][] C=matrixFromDouble(2);
B = subsasgn(B,new double[][][]{colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(2))},numel(null,new double[][][]{A}));

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
