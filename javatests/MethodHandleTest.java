import java.lang.invoke.MethodHandle;
import java.lang.invoke.MethodHandles;
import java.lang.invoke.MethodType;


public class MethodHandleTest {
  public static void main(String... args) throws Throwable {
    bsxfun();
  }

  public static double[][] test(double[][] t, double[][] t1){
        return new double[][]{{t.length+t1.length}};
            }
    public static void bsxfun() throws Throwable {
        
       
        
        double[][] res = new double[0][0];
        MethodType mt; MethodHandle mh;
        MethodHandles.Lookup lookup = MethodHandles.lookup();
        mt = MethodType.methodType(double[][].class,double[][].class,double[][].class);
        mh = lookup.findStatic(MethodHandleTest.class, "test", mt);
        System.out.println(mh.invoke(new double[][]{{2,1,2}},new double[][]{{2,1,4,5}}));
}

}
