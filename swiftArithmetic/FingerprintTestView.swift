import SwiftUI
import FingerprintJS
import HotSwiftUI



struct FingerprintTestView: View {
    @ObserveInjection var redraw
    @State private var fingerprintText: String?
    @State private var isLoading = false

    var body: some View {
        VStack(spacing: 12) {
            Text("Fingerpr大萨达你撒娇")
                .font(.headline)
            
            Text("Finger撒娇")
                .font(.headline)
            
            Text("Finger撒娇")
                .font(.subheadline)
            Text("d都没看见开单尽快")
                .font(.subheadline)

            if isLoading {
                ProgressView()
            } else if let fingerprintText, !fingerprintText.isEmpty {
                Text(fingerprintText)
                    .font(.footnote)
                    .textSelection(.enabled)
                    .multilineTextAlignment(.leading)
            } else {
                Text("No fingerprint yet.")
                    .foregroundStyle(.secondary)
                    .font(.footnote)
            }

            Spacer()
        }
        .padding()
        .task {
//             避免视图重建时重复拉取
            guard fingerprintText == nil, !isLoading else { return }
            isLoading = true
            let fingerprinter = FingerprinterFactory.getInstance()
            let fingerprint = await fingerprinter.getFingerprint()
            await MainActor.run {
                fingerprintText = fingerprint
                isLoading = false
            }
            print("[FingerprintJS] fingerprint =", fingerprint ?? "nil")
        }
        .enableInjection()
    }
}

#Preview {
    FingerprintTestView()
}

