import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] C=horzcat(horzcat(matrixFromDouble(3),matrixFromDouble(4)),matrixFromDouble(8));
double[][] A=ctranspose(horzcat(horzcat(matrixFromDouble(4),matrixFromDouble(5)),matrixFromDouble(6)));

System.out.println("A=");
printMatrix(A);
System.out.println();
System.out.println("C=");
printMatrix(C);
System.out.println();
}
}
