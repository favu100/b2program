package de.hhu.stup.btypes;

import java.math.BigInteger;

import de.hhu.stups.btypes.BInteger;

import org.junit.Test;
import org.junit.experimental.runners.Enclosed;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import static org.junit.Assert.assertEquals;

@RunWith(Enclosed.class)
public class BIntegerTest {

	private static BInteger toBInt(Object o) {
		if (o instanceof BInteger) {
			return (BInteger) o;
		} else if (o instanceof Integer) {
			return BInteger.of((int) o);
		} else if (o instanceof Long) {
			return BInteger.of((int) o);
		} else if (o instanceof BigInteger) {
			return BInteger.of((BigInteger) o);
		} else {
			throw new IllegalArgumentException();
		}
	}

	@RunWith(Parameterized.class)
	public static class PowerTest {

		@Parameterized.Parameters(name = "{index}: power({0}, {1}) = {2}")
		public static Object[][] data() {
			return new Object[][] {
					{ 0, 0, 1 },
					{ 0, 1, 0 },
					{ 0, 2, 0 },
					{ 0, 3, 0 },
					{ 0, 4, 0 },
					{ 0, 5, 0 },
					{ 1, 0, 1 },
					{ 1, 1, 1 },
					{ 1, 2, 1 },
					{ 1, 3, 1 },
					{ 1, 4, 1 },
					{ 1, 5, 1 },
					{ 2, 0, 1 },
					{ 2, 1, 2 },
					{ 2, 2, 4 },
					{ 2, 3, 8 },
					{ 2, 4, 16 },
					{ 2, 5, 32 },
					{ 3, 0, 1 },
					{ 3, 1, 3 },
					{ 3, 2, 9 },
					{ 3, 3, 27 },
					{ 3, 4, 81 },
					{ 3, 5, 243 },
			};
		}

		@Parameterized.Parameter
		public Object base;
		@Parameterized.Parameter(1)
		public Object power;
		@Parameterized.Parameter(2)
		public Object expected;

		@Test
		public void test() {
			BInteger base = toBInt(this.base);
			BInteger power = toBInt(this.power);
			BInteger expected = toBInt(this.expected);
			assertEquals(expected, base.power(power));
		}
	}
}
