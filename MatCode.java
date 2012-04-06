import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=lor(land(matrixFromDouble(7),matrixFromDouble(0)),matrixFromDouble(7));
double[][] C1=land(matrixFromDouble(4),matrixFromDouble(0));
double[][] A1=lor(add(uminus(matrixFromDouble(2)),matrixFromDouble(7)),matrixFromDouble(0));

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("A1=");
printMatrix(A1);
System.out.println();
System.out.println("C1=");
printMatrix(C1);
System.out.println();
}
}
