# frozen_string_literal: true

require 'spec_helper'

RSpec.describe Spree::LocaleController, type: :controller do
  include_context "fr locale"

  context 'switch_to_locale specified' do
    context "available locale" do
      it 'sets locale and redirects' do
        get :set, params: { switch_to_locale: 'fr' }
        expect(I18n.locale).to eq :fr
        expect(response).to redirect_to('/')
        expect(session[:locale]).to eq('fr')
        expect(flash[:notice]).to eq(I18n.t("spree.locale_changed"))
      end
    end

    context "unavailable locale" do
      it 'does not change locale and redirects' do
        get :set, params: { switch_to_locale: 'klingon' }
        expect(I18n.locale).to eq :en
        expect(response).to redirect_to('/')
        expect(flash[:error]).to eq(I18n.t("spree.locale_not_changed"))
      end
    end
  end

  context 'locale specified' do
    context "available locale" do
      it 'sets locale and redirects' do
        get :set, params: { locale: 'fr' }
        expect(I18n.locale).to eq :fr
        expect(response).to redirect_to('/')
        expect(flash[:notice]).to eq(I18n.t("spree.locale_changed"))
      end
    end

    context "unavailable locale" do
      it 'does not change locale and redirects' do
        get :set, params: { locale: 'klingon' }
        expect(I18n.locale).to eq :en
        expect(response).to redirect_to('/')
        expect(flash[:error]).to eq(I18n.t("spree.locale_not_changed"))
      end
    end
  end

  context 'both locale and switch_to_locale specified' do
    it 'uses switch_to_locale value' do
      get :set, params: { locale: 'en', switch_to_locale: 'fr' }
      expect(I18n.locale).to eq :fr
      expect(response).to redirect_to('/')
      expect(flash[:notice]).to eq(I18n.t("spree.locale_changed"))
    end
  end
end
