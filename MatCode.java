import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] C=horzcat(horzcat(matrixFromDouble(3),matrixFromDouble(4)),matrixFromDouble(0));
double[][] A=or(C,matrixFromDouble(70));
double[][] C1=horzcat(horzcat(matrixFromDouble(3),matrixFromDouble(4)),matrixFromDouble(0));
double[][] A1=and(C1,matrixFromDouble(7));

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("A1=");
printMatrix(A1);
System.out.println();
System.out.println("C=");
printMatrix(C);
System.out.println();
System.out.println("C1=");
printMatrix(C1);
System.out.println();
}
}
