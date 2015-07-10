package test;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import org.apache.commons.cli.ParseException;
import org.junit.Before;
import org.junit.Test;

import de.fosd.jdime.*;

;

public class oneAndTwo {

//	@Before
//	public void init()  {
//		try {
//			Main.main(new String[] { "-mode", "nway", "-output",
//					"testcpp/1/12.cpp", "testcpp/1/1.cpp", "testcpp/1/2.cpp" });
//		} catch (IOException e) {
//			e.printStackTrace();
//		} catch (ParseException e) {
//			e.printStackTrace();
//		} catch (InterruptedException e) {
//			e.printStackTrace();
//		}
//
//	}

	@Test
	public void test() throws IOException {
//		init();
		BufferedReader result_br = new BufferedReader(new FileReader(
				"testcpp/1/12.cpp"));
		BufferedReader exp_br = new BufferedReader(new FileReader(
				"testcpp/1/expect.cpp"));
		assertNotNull(result_br);
		String result, expect_result = "";

		try {
			StringBuilder sb = new StringBuilder();
			String line = result_br.readLine();

			while (line != null) {
				sb.append(line);
				sb.append(System.lineSeparator());
				line = result_br.readLine();
			}
			result = sb.toString();
		} finally {
			result_br.close();
		}

		try {
			StringBuilder sb = new StringBuilder();
			String line = exp_br.readLine();

			while (line != null) {
				sb.append(line);
				sb.append(System.lineSeparator());
				line = exp_br.readLine();
			}
			expect_result = sb.toString();
		} finally {
			exp_br.close();
		}
		 assertEquals(result, expect_result);
		// assertNotNull(result);
	}

}
