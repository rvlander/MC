import static org.mc.mcjavacore.MCJOperators.*;
import static org.mc.mcfunctions.MCJFunctions.*;
import org.mc.mcfunctions.MCJOutputArg;
import static org.mc.mcjavautils.MCJUtils.*;
import static org.mc.mcjavacore.MCJBaseFunctions.*;
public class MatCode{
public static void main(String args[]) throws Exception{
double[][] A=vertcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),horzcat(matrixFromDouble(3),matrixFromDouble(1)));
double[][] B=vertcat(horzcat(matrixFromDouble(1),matrixFromDouble(2)),horzcat(matrixFromDouble(3),matrixFromDouble(2)));
double[][] C=colon(matrixFromDouble(1),matrixFromDouble(1),matrixFromDouble(5));
if(any(A)){C=add(C,matrixFromDouble(2));
}else if(any(B)){C=add(C,matrixFromDouble(789));
}else{C=minus(C,matrixFromDouble(10));
};

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
