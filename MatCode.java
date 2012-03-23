import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] C=vertcat(colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(5)),horzcat(horzcat(horzcat(horzcat(matrixFromDouble(3),matrixFromDouble(5)),matrixFromDouble(6)),matrixFromDouble(7)),matrixFromDouble(9)));
C=minus(mtimes(matrixFromDouble(4),matrixFromDouble(9)),uminus(matrixFromDouble(5)));

System.out.println("C=");
printMatrix(C);
System.out.println();
}
}
