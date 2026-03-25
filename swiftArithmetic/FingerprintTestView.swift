import SwiftUI
import FingerprintJS

struct FingerprintTestView: View {
    @State private var fingerprintText: String?
    @State private var isLoading = false

    var body: some View {
        VStack(spacing: 12) {
            Text("FingerprintJS Test")
                .font(.headline)

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
            // 避免视图重建时重复拉取
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
    }
}

#Preview {
    FingerprintTestView()
}

