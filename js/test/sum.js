function sum(filePath) {
	return new Promise((resolve, reject) => {
		var xhr = new XMLHttpRequest();

		xhr.open("GET", filePath, true);
		xhr.onreadystatechange = function () {
			if (xhr.readyState === 4) {
				var data = xhr.responseText; // 外部ファイルの内容

				resolve(Module.ccall(
					'sumFromText',
					'string',
					['string'],
					[data]));
			}
		};
		xhr.send();
	});
}

describe('sum 関数のテスト', function () {
	describe('wasm関数を直接呼び出し', function () {

		it('3つの数値とテキストとを与えると合計値とテキストを合わせた文字列を返す', function () {
			expect(Module.ccall(
				'sum',
				'string',
				['number', 'number', 'number', 'string'],
				[1, 2, 3, 'テキスト']))
				.toBe('6 テキスト');
		});
	});

	describe('JavaScript側でファイルを読み込んでからwasm関数を呼び出し', function () {
		it('テキストファイルの内容を与えると合計値とテキストを合わせた文字列を返す', function (done) {
			sum('./sum_input').then(result => {
				expect(result).toBe('6 test');

				done();
			});
		});
	});
});
