package test;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import org.apache.commons.cli.ParseException;
import org.junit.Before;
import org.junit.Test;

import de.fosd.jdime.Main;

public class oneTwoThree {

//	@Before
//	public void init() throws IOException {
//		try {
//			Main.main(new String[] { "-mode", "structured", "-output",
//					"testcpp/2/12.cpp", "testcpp/2/1.cpp", "testcpp/2/2.cpp" });
//		} catch (ParseException e) {
//			e.printStackTrace();
//		} catch (InterruptedException e) {
//			e.printStackTrace();
//		}
//	}

	@Test
	public void test() throws IOException {
//		init();
		BufferedReader result_br = new BufferedReader(new FileReader(
				"testcpp/2/AB.cpp"));
		BufferedReader exp_br = new BufferedReader(new FileReader(
				"testcpp/2/expect.cpp"));
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
//			System.out.print(result);
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
//			System.out.print(expect_result);
		} finally {
			exp_br.close();
		}
		 assertEquals(result, expect_result);
	}

}
