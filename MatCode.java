import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=horzcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),matrixFromDouble(3));
double[][] B=matrixFromDouble(5);
double[][] C=add(A,B);

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
