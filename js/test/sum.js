describe('sum 関数のテスト', function () {
	it('3つの数値とテキストとを与えると合計値とテキストを合わせた文字列を返す', function () {
		expect(Module.ccall(
			'sum',
			'string',
			['number', 'number', 'number', 'string'],
			[1, 2, 3, 'テキスト']))
			.toBe('6 テキスト');
	});
});
