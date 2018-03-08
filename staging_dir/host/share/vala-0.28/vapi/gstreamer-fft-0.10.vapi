/* gstreamer-fft-0.10.vapi generated by vapigen, do not modify. */

[CCode (cprefix = "Gst", gir_namespace = "GstFft", gir_version = "0.10", lower_case_cprefix = "gst_")]
namespace Gst {
	[CCode (cheader_filename = "gst/fft/gstfftf32.h")]
	[Compact]
	public class FFTF32 {
		public void* cfg;
		public bool inverse;
		public int len;
		[CCode (has_construct_function = false)]
		public FFTF32 (int len, bool inverse);
		public void fft (float timedata, Gst.FFTF32Complex freqdata);
		public void inverse_fft (Gst.FFTF32Complex freqdata, float timedata);
		public void window (float timedata, Gst.FFTWindow window);
	}
	[CCode (cheader_filename = "gst/fft/gstfftf32.h")]
	[Compact]
	public class FFTF32Complex {
		public float i;
		public float r;
	}
	[CCode (cheader_filename = "gst/fft/gstfftf64.h")]
	[Compact]
	public class FFTF64 {
		public void* cfg;
		public bool inverse;
		public int len;
		[CCode (has_construct_function = false)]
		public FFTF64 (int len, bool inverse);
		public void fft (double timedata, Gst.FFTF64Complex freqdata);
		public void inverse_fft (Gst.FFTF64Complex freqdata, double timedata);
		public void window (double timedata, Gst.FFTWindow window);
	}
	[CCode (cheader_filename = "gst/fft/gstfftf64.h")]
	[Compact]
	public class FFTF64Complex {
		public double i;
		public double r;
	}
	[CCode (cheader_filename = "gst/fft/gstffts16.h")]
	[Compact]
	public class FFTS16 {
		public void* cfg;
		public bool inverse;
		public int len;
		[CCode (has_construct_function = false)]
		public FFTS16 (int len, bool inverse);
		public void fft (int16 timedata, Gst.FFTS16Complex freqdata);
		public void inverse_fft (Gst.FFTS16Complex freqdata, int16 timedata);
		public void window (int16 timedata, Gst.FFTWindow window);
	}
	[CCode (cheader_filename = "gst/fft/gstffts16.h")]
	[Compact]
	public class FFTS16Complex {
		public int16 i;
		public int16 r;
	}
	[CCode (cheader_filename = "gst/fft/gstffts32.h")]
	[Compact]
	public class FFTS32 {
		public void* cfg;
		public bool inverse;
		public int len;
		[CCode (has_construct_function = false)]
		public FFTS32 (int len, bool inverse);
		public void fft (int32 timedata, Gst.FFTS32Complex freqdata);
		public void inverse_fft (Gst.FFTS32Complex freqdata, int32 timedata);
		public void window (int32 timedata, Gst.FFTWindow window);
	}
	[CCode (cheader_filename = "gst/fft/gstffts32.h")]
	[Compact]
	public class FFTS32Complex {
		public int32 i;
		public int32 r;
	}
	[CCode (cheader_filename = "gst/fft/gstfft.h", cprefix = "GST_FFT_WINDOW_", has_type_id = false)]
	public enum FFTWindow {
		RECTANGULAR,
		HAMMING,
		HANN,
		BARTLETT,
		BLACKMAN
	}
	[CCode (cheader_filename = "gst/fft/gstfft.h")]
	public static int fft_next_fast_length (int n);
}